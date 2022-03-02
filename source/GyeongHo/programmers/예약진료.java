import java.util.*;
import java.text.*;
import java.io.*;

public class 예약진료 {
    
    public static void main(String[] args) {
        Solution tmp = new Solution();
        String[][] booked = new String[][] {{"09:55", "hae"}, {"10:05", "jee"}};
        String[][] unbooked = new String[][] {{"10:04", "hee"}, {"14:07", "eom"}};
        String[] ans = tmp.solution(booked, unbooked);
        for(int i = 0; i < ans.length; ++i) {
            System.out.print(ans[i]);
            System.out.print(" ");
        }
    }
}

class Solution {
    public Date addTenM(Date baseTime) {
        Calendar cal = Calendar.getInstance();
        cal.setTime(baseTime);
        cal.add(Calendar.MINUTE, 10);
        baseTime = cal.getTime();
        return baseTime;
    }
    public String[] solution(String[][] booked, String[][] unbooked) {
        String[] ans = new String[booked.length + unbooked.length];
        Date baseTime = null, curB = null, curU = null;
        SimpleDateFormat sdf = new SimpleDateFormat("HH:mm");
        try {
            curB = sdf.parse(booked[0][0]);
            curU = sdf.parse(unbooked[0][0]);
        } catch(Exception ex) {
            return ans;
        }
        baseTime = curB.compareTo(curU) < 0 ? curB : curU;
        
        int Bidx = 0, Uidx = 0;
        while (Bidx < booked.length && Uidx < booked.length) {
            try {
                curB = sdf.parse(booked[Bidx][0]);
                curU = sdf.parse(unbooked[Uidx][0]);
            } catch(Exception ex) {
                return ans;
            }
            if (curB.compareTo(baseTime) <= 0) {
                baseTime = addTenM(baseTime);
                ans[Uidx + Bidx] = booked[Bidx++][1];
            }
            else {
                baseTime = addTenM(baseTime);
                ans[Bidx + Uidx] = unbooked[Uidx++][1];
            }
        }
        while (Bidx < booked.length)
            ans[Uidx + Bidx] = booked[Bidx++][1];
        while (Uidx < unbooked.length)
            ans[Bidx + Uidx] = unbooked[Uidx++][1];
        
        return ans;
    }
}
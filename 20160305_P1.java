import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class P1 {

    private static Scanner scanner;
    private int n;
    private List<Integer> pass;
    private List<Integer> fail;

    private void printList(List<Integer> list) {

        for (int i = 0; i < list.size(); i++) {
            if (i != 0) {
                System.out.print(" ");
            }
            System.out.print(list.get(i));
        }
    }

    P1 () {

        scanner = new Scanner(System.in);
        n = scanner.nextInt();
        pass = new ArrayList<Integer>(n);
        fail = new ArrayList<Integer>(n);
        for (int i = 0; i < n; i++) {
            int temp = scanner.nextInt();
            if (temp < 60) {
                fail.add(temp);
            } else {
                pass.add(temp);
            }
        }
        pass.sort(null);
        fail.sort(null);

        printList(fail);
        System.out.print(" ");
        printList(pass);
        System.out.println();

        if (fail.isEmpty()) {
            System.out.println("best case");
        } else {
            System.out.println(fail.get(fail.size()-1));
        }

        if (pass.isEmpty()) {
            System.out.println("worst case");
        } else {
            System.out.println(pass.get(0));
        }
    }

    public static void main(String... arg) {

        new P1();
    }
}

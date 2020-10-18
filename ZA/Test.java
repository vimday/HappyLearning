import java.util.StringTokenizer;

public class Test {

    public static void main(String[] args) {

        String[][] s = { { "helloworld", "hello world" }, { "this is", "a java program" } };
        System.out.println(new StringTokenizer(s[1][1]).countTokens());
        System.out.println((new StringTokenizer(s[1][1])).countTokens() > 2);

    }

}
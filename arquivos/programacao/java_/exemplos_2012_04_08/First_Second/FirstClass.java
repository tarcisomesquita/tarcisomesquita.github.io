import java.util.Locale;

public class FirstClass {
    public String getString() {
        System.out.println(java.util.Locale.getDefault());
        return Locale.getDefault().getDisplayName();
    }
}

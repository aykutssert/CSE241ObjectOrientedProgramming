
public class Text extends ObjectBase implements NonVisual, NonPlayable {

    private String other;

    // The constructor function of the Text class assigns the name, other information.
    public Text(String _name, String _other) {
        super(_name, 3);
        this.other = _other;
    }

    /**
     * 
     * @return {@code other}
     */
    public String getOtherInfo() {
        return this.other;
    }

    // This function prints Text's information to the screen.
    @Override
    public void info() {
        System.out.println(this.getName() + "-" + other);
    }

    // This function allows Text to be displayed.
    @Override
    public void display() {
        System.out.println(this.getName() + " is displaying...");
    }

}
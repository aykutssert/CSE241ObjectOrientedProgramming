
public class Image extends ObjectBase implements Visual, NonPlayable {

    private String dimension, other;

    // The constructor function of the Image class assigns the name, dimension and other information.
    public Image(String _name, String _dimension, String _other) {
        super(_name, 3);
        this.dimension = _dimension;
        this.other = _other;

    }

    /**
     * 
     * @return {@code dimension}
     */
    public String getDimensionInfo() {
        return this.dimension;
    }

    /**
     * 
     * @return {@code other}
     */
    public String getOtherInfo() {
        return this.other;
    }

    // This function prints Image's information to the screen.
    @Override
    public void info() {
        System.out.println(this.getName() + "-" + dimension + "-" + other);

    }

    // This function allows Image to be displayed.
    @Override
    public void display() {
        System.out.println(this.getName() + " is displaying...");
    }

}

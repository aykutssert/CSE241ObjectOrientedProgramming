abstract class ObjectBase{

    private String name;
    private int flag;

    public ObjectBase(final String name,final int _flag) {
        this.name = name;
        this.flag=_flag;
    }

    //getter for name
    public String getName() {
        return name;
    }
    public abstract void info(); // abstract method. 

    //setter for controlling add or remove.
    public void setFlag(final int _flag){
        this.flag=_flag;
    }
    //getter for control flag.
    public int getFlag(){
        return flag;
    }

}
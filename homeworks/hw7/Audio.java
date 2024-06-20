

public class Audio extends ObjectBase implements NonVisual , Playable{

    private String duration , other;

    // The constructor function of the Audio class assigns the name, duration and other information.
    public Audio(String _name , String _duration , String _other){
        super(_name,3);
        this.duration=_duration;
        this.other=_other;
      
    }

     /**
     * 
     * @return {@code duration} 
     */
    public String getDurationInfo(){
        return this.duration;
    }

      /**
     * 
     * @return {@code other} 
     */
    public String getOtherInfo(){
        return this.other;
    }

    // This function prints Audio's information to the screen.
    @Override
    public void info(){
        System.out.println(this.getName() + "-" + duration + "-" + other);
    }

    // This function allows Audio to be played.
    @Override
    public void play(){
        System.out.println(this.getName()+" is playing...");
    }

    
}
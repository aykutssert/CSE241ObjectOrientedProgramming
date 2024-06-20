make: all run clean
# for compile
JAVAC = javac

# for run java virtual machine
JAVA = java

# source files
SOURCES = Main.java Dataset.java Image.java Audio.java Text.java Video.java ObjectBase.java Playable.java NonPlayable.java Visual.java NonVisual.java IObserver.java Player.java Viewer.java

.PHONY: all clean

all: $(SOURCES:.java=.class)

# compile all class
%.class: %.java
	$(JAVAC) $<

# run compiled files
run: all
	$(JAVA) Main

# clean
clean:
	@rm -f *.class
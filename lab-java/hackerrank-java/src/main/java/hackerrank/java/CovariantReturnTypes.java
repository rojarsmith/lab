package hackerrank.java;

// Covariant Return Types.

class Flower {

    String whats_Your_Name() {
        return "I have many names and types";
    }
}

class Jasmine extends Flower {

    @Override
    String whats_Your_Name() {
        return "Jasmine";
    }
}

class State {

    Flower your_National_Flower() {
        return new Flower();
    }
}

class WestBengal extends State {

    @Override
    Jasmine your_National_Flower() {
        return new Jasmine();
    }
}

public class CovariantReturnTypes {

   

    public static void lab1() {
        State p1 = new State();
        WestBengal p2 = new WestBengal();
        
        System.out.println(p1.your_National_Flower().whats_Your_Name());
        System.out.println(p2.your_National_Flower().whats_Your_Name());
    }
}

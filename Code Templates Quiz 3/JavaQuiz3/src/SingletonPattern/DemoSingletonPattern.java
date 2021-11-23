package SingletonPattern;

public class DemoSingletonPattern {
    public static void main(String[] args) {
        Singleton c1 = Singleton.getOnlyInstance();
        c1.addName("Jack Lemon");
        c1.addUsername("jlemon");
        c1.addPassword("jl1234");

        Singleton c2 = Singleton.getOnlyInstance();
        c2.addName("Merry Leu");
        c2.addUsername("mleu");
        c2.addPassword("orange1234");

    }
}

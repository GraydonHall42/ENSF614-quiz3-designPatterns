package SingletonPattern;

import java.util.ArrayList;

public class Singleton {
    private static Singleton onlyInstance;
    private ArrayList<String> usernameList;
    private ArrayList<String> passwordList;
    private ArrayList<String> nameList;

    public Singleton() {
        this.usernameList = new ArrayList<String >();
        this.passwordList = new ArrayList<String >();
        this.nameList = new ArrayList<String >();
    }

    public static Singleton getOnlyInstance(){
        if(onlyInstance==null){
            onlyInstance = new Singleton();
        }
        return onlyInstance;
    }

    public void addUsername(String userName) {
        this.usernameList.add(userName);
        System.out.println("added userName: " +userName);
    }

    public void addPassword(String password) {
        this.passwordList.add(password);
        System.out.println("added password: " + password);
    }

    public void addName(String name) {
        this.nameList = nameList;
        System.out.println("added name: " + name);
    }
}

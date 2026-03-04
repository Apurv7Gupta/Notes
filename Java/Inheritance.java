public class Inheritance {

    public static class Base {
        private int age;
        private String name;

        public int getAge() {
            return age;
        }

        public void setAge(int newAge) {
            this.age = newAge;

        }

        public String getName() {
            return name;
        }

        public void setName(String newName) {
            this.name = newName;
        }
    }

    public static class Derived extends Base {

        @Override
        public void setAge(int newAge) {
            if (newAge < 18) {
                throw new IllegalArgumentException("Age cannot be less than 18!");
            }
            super.setAge(newAge);
        }
    }

    public static void main(String[] args) {

        Base baseObj = new Base();
        baseObj.setAge(17); // Does not throw error
        int val = baseObj.getAge();
        System.out.println(val);

        Derived derivedObj = new Derived();
        derivedObj.setName("Gurt");
        String value = derivedObj.getName();
        System.out.println(value);

    }

}

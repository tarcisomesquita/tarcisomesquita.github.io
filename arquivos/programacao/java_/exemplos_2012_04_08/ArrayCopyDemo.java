// clear ; javac ArrayCopyDemo.java && java ArrayCopyDemo

// public static void arraycopy(Object src, int srcPos, Object dest, int destPos, int length)

class ArrayCopyDemo {
   public static void main(String[] args) {
      char[] copyFrom = { 'd', 'e', 'c', 'a', 'f', 'f', 'e', 'i', 'n', 'a', 't', 'e', 'd' };
      char[] copyTo = new char[7];
      
      System.arraycopy(copyFrom, 2, copyTo, 0, 7);
      System.out.println(new String(copyTo));
   }
}

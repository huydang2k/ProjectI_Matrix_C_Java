# ProjectI_Matrix_C_Java
Để cho thuận tiện, cả hai chương trình em đều dịch và chạy trên terminal.
1. Java Call C
   
   Cần cung cấp đường dẫn tuyệt đối của file liên kết động "lib.so" trong câu lệnh System.load();
   
    static 
    {
    
            System.load("/<path/to/repository>/Matrix_prj/Java-Call-C/lib.so");
   
   }
        
       
   Có thể thay thế bằng System.loadLibrary() để chỉ cần cung cấp đường dẫn tương đối.
 2. C Call Java
    
    Dịch
    
    gcc -o Matrix -L/<path/to/JavaJDK>/jre/lib/amd64/server/ -I/<path/to/JavaJDK>/include -I/<path/to/JavaJDK>/include/linux -L/<path/to/JavaJDK>/bin/java Matrix.c -ljvm
    
    Cần khai báo thêm biến môi trường để chạy 
    
    export LD_LIBRARY_PATH="/<path/to/JavaJDK>/jre/lib/amd64/server/"
    
    Chạy
    
    ./Matrix

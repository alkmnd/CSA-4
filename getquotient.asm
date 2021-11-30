
global GetQuotient
GetQuotient:
mov ecx, -1    
    xor al, al      
    cld            
    repne   scasb   
    neg ecx
    sub ecx, 1     
    mov eax, ecx
    ret
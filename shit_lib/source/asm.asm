printf proto

.data
sss byte "我有%d元人民币",0

.code
test_asm proc
	sub  rsp, 028h
	
	mov  rdx, 996
	lea  rcx, sss
	call printf
	
	add  rsp, 028h
	ret
test_asm endp

end

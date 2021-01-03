section.text:
	global _ft_read
	extern ___error

_ft_read:
	mov rax, 0x2000003
	syscall
	jc _error
	ret

_error:
	mov r15, rax
	push r15
	call ___error
	pop qword[rax]
	mov rax, -1
	ret
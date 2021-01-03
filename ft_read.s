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
	call ___error
	mov [rax], r15
	mov rax, -1
	ret
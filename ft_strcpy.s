section.text:
	global _ft_strcpy

_ft_strcpy:
	xor rax, rax
	cmp rsi, BYTE 0
	je _null_end
	_loop:
		mov bl, BYTE[rsi + rax]
		mov BYTE[rdi + rax], bl
		cmp BYTE[rsi + rax], 0
		je _end
		inc rax
		jmp _loop

_null_end:
	ret

_end:
	mov rax, rdi
	ret
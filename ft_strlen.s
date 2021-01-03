section.text:
	global _ft_strlen

_ft_strlen:
	xor rax, rax
	_loop:
		cmp BYTE[rdi + rax], 0
		je _end
		inc rax
		jmp _loop

_end:
	ret
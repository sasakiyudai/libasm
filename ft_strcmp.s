section.text:
	global _ft_strcmp

_ft_strcmp:
	xor rax, rax
	xor rbx, rbx
	xor rcx, rcx

	_loop:
		mov al, BYTE[rdi + rcx]
		mov bl, BYTE[rsi + rcx]
		cmp al, BYTE 0
		je _end
		cmp bl, BYTE 0
		je _end
		inc rcx
		cmp al, bl
		je _loop
		jmp _end

_end:
	sub rax, rbx
	ret
section.test:
	global _ft_strdup
	extern _ft_strcpy
	extern _ft_strlen
	extern _malloc

_ft_strdup:
	push rdi
	mov rax, 0
	cmp rdi, 0
	je _just_end
	call _ft_strlen
	mov rdi, rax
	inc rdi
	call _malloc
	cmp rax, 0
	je _just_end
	mov rdi, rax
	pop rsi
	call _ft_strcpy
	ret

_just_end:
	ret

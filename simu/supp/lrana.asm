	;;      unsigned long lrana(unsigned long s)
	;;      generation employs a congruential method mod 2^31-1

[global lrana]

[section .data]	
	mm    dd  16807

[section .text]

  lrana
	mov      eax,dword [esp+4]
	mul      dword [mm]
	shld     edx,eax,1
	btr      eax,31
	add      eax,edx
	bt       eax,31
	jnc      .A
	add      eax,1
	btr      eax,31
 .A
	ret

	end

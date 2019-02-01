	;;      unsigned long lranb(unsigned long s)
	;;      generation employs a congruential method mod 2^31-1

[global lranb]

[section .data]	
	mm    dd  48271

[section .text]

  lranb
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

.syntax unified
	.align 2, 0
	.global task_frd_jack_3
	.thumb
	.thumb_func
	.type task_frd_jack_3, %function
task_frd_jack_3: @ 08048750
	push {r4, lr}
	adds r4, r0, #0x0
	movs r1, #0xA6
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08048768
	ldr r0, _08048764 @ =0x02039B84
	b _0804876A
_08048764: .4byte 0x02039B84
_08048768:
	ldr r0, _0804878C @ =0x02039B9C
_0804876A:
	ldr r3, [r0, #0x00]
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	ldr r2, _08048790 @ =0xFFDFFFFF
	ands r0, r2
	str r0, [r3, #0x68]
	str r1, [r3, #0x6C]
	ldr r0, [r4, #0x1C]
	bl ReleaseObjPalette
	adds r0, r4, #0x0
	bl TaskPoolDestroy
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0804878C: .4byte 0x02039B9C
_08048790: .4byte 0xFFDFFFFF
.syntax divided

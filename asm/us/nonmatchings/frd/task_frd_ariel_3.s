.syntax unified
	.align 2, 0
	.global task_frd_ariel_3
	.thumb
	.thumb_func
	.type task_frd_ariel_3, %function
task_frd_ariel_3: @ 08047464
	push {r4, lr}
	adds r4, r0, #0x0
	movs r1, #0xA6
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0804747C
	ldr r0, _08047478 @ =0x02039B84
	b _0804747E
_08047478: .4byte 0x02039B84
_0804747C:
	ldr r0, _080474A0 @ =0x02039B9C
_0804747E:
	ldr r3, [r0, #0x00]
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	ldr r2, _080474A4 @ =0xFFDFFFFF
	ands r0, r2
	str r0, [r3, #0x68]
	str r1, [r3, #0x6C]
	ldr r0, [r4, #0x1C]
	bl func_08002C10
	adds r0, r4, #0x0
	bl func_08000F0C
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080474A0: .4byte 0x02039B9C
_080474A4: .4byte 0xFFDFFFFF
.syntax divided

.syntax unified
	.align 2, 0
	.global task_smn_bambi_3
	.thumb
	.thumb_func
	.type task_smn_bambi_3, %function
task_smn_bambi_3: @ 08042668
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r1, _0804267C @ =0x00000163
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08042684
	ldr r0, _08042680 @ =0x02039B84
	b _08042686
	.byte 0x00, 0x00
_0804267C: .4byte 0x00000163
_08042680: .4byte 0x02039B84
_08042684:
	ldr r0, _080426A8 @ =0x02039B9C
_08042686:
	ldr r3, [r0, #0x00]
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	ldr r2, _080426AC @ =0xFFDFFFFF
	ands r0, r2
	str r0, [r3, #0x68]
	str r1, [r3, #0x6C]
	ldr r0, [r4, #0x04]
	bl func_08002C10
	adds r0, r4, #0x0
	adds r0, #0x20
	bl func_08000F0C
	pop {r4}
	pop {r0}
	bx r0
_080426A8: .4byte 0x02039B9C
_080426AC: .4byte 0xFFDFFFFF
.syntax divided

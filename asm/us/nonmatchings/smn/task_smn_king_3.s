.syntax unified
	.align 2, 0
	.global task_smn_king_3
	.thumb
	.thumb_func
	.type task_smn_king_3, %function
task_smn_king_3: @ 08045404
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r1, _08045418 @ =0x0000015D
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08045420
	ldr r0, _0804541C @ =0x02039B84
	b _08045422
	.byte 0x00, 0x00
_08045418: .4byte 0x0000015D
_0804541C: .4byte 0x02039B84
_08045420:
	ldr r0, _08045444 @ =0x02039B9C
_08045422:
	ldr r3, [r0, #0x00]
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	ldr r2, _08045448 @ =0xFFDFFFFF
	ands r0, r2
	str r0, [r3, #0x68]
	str r1, [r3, #0x6C]
	ldr r0, [r4, #0x04]
	bl ReleaseObjPalette
	adds r0, r4, #0x0
	adds r0, #0x20
	bl TaskPoolDestroy
	pop {r4}
	pop {r0}
	bx r0
_08045444: .4byte 0x02039B9C
_08045448: .4byte 0xFFDFFFFF
.syntax divided

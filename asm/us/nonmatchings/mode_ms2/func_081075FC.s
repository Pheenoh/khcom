.syntax unified
	.align 2, 0
	.global func_081075FC
	.thumb
	.thumb_func
	.type func_081075FC, %function
func_081075FC: @ 081075FC
	push {r4, r5, lr}
	add sp, #-0x004
	movs r0, #0x00
	bl func_08005130
	adds r2, r0, #0x0
	movs r0, #0xE8
	lsls r0, r0, #0x02
	adds r2, r2, r0
	ldr r0, _08107644 @ =0x02035E48
	movs r1, #0x00
	ldsh r0, [r0, r1]
	ldr r5, _08107648 @ =0x09A0693C
	movs r4, #0x02
	str r4, [sp, #0x000]
	adds r1, r5, #0x0
	movs r3, #0x20
	bl func_08101588
	movs r0, #0x00
	bl func_08005130
	adds r2, r0, #0x0
	movs r0, #0xF8
	lsls r0, r0, #0x02
	adds r2, r2, r0
	str r4, [sp, #0x000]
	movs r0, #0x63
	adds r1, r5, #0x0
	movs r3, #0x20
	bl func_08101588
	add sp, #0x004
	pop {r4, r5}
	pop {r0}
	bx r0
_08107644: .4byte 0x02035E48
_08107648: .4byte 0x09A0693C
.syntax divided

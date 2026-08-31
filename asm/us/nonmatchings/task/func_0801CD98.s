.syntax unified
	.align 2, 0
	.global func_0801CD98
	.thumb
	.thumb_func
	.type func_0801CD98, %function
func_0801CD98: @ 0801CD98
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x008
	mov r8, r0
	adds r4, r1, #0x0
	adds r1, r3, #0x0
	ldr r5, [sp, #0x020]
	ldr r6, [sp, #0x024]
	ldr r7, [sp, #0x028]
	lsls r2, r2, #0x04
	ldr r0, _0801CDF8 @ =0x0813B09C
	adds r2, r2, r0
	str r2, [sp, #0x000]
	str r4, [sp, #0x004]
	adds r0, r4, #0x0
	bl func_0801CD74
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	adds r3, r7, #0x0
	bl func_0801CD8C
	movs r1, #0x00
	movs r0, #0x00
	strh r0, [r4, #0x14]
	str r0, [r4, #0x10]
	movs r0, #0x80
	lsls r0, r0, #0x04
	strh r0, [r4, #0x16]
	movs r0, #0x80
	lsls r0, r0, #0x01
	str r0, [r4, #0x24]
	str r0, [r4, #0x20]
	adds r4, #0x28
	strb r1, [r4, #0x00]
	ldr r1, _0801CDFC @ =0x09EDADC8
	mov r0, r8
	mov r2, sp
	bl TaskCreate
	add sp, #0x008
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0801CDF8: .4byte 0x0813B09C
_0801CDFC: .4byte 0x09EDADC8
.syntax divided

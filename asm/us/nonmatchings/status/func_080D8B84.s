.syntax unified
	.align 2, 0
	.global func_080D8B84
	.thumb
	.thumb_func
	.type func_080D8B84, %function
func_080D8B84: @ 080D8B84
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x024
	str r0, [sp, #0x020]
	mov r10, r1
	mov r9, r2
	mov r1, sp
	ldr r0, _080D8C28 @ =0x096FDE24
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3}
	stm r1!, {r2, r3}
	ldr r2, _080D8C2C @ =0x02039BB0
	ldr r0, [r2, #0x08]
	movs r1, #0x08
	ands r0, r1
	movs r4, #0x03
	mov r8, r4
	cmp r0, #0x00
	beq _080D8BBA
	movs r0, #0x01
	mov r8, r0
_080D8BBA:
	movs r6, #0x00
	movs r7, #0x00
_080D8BBE:
	lsls r0, r7, #0x02
	mov r1, sp
	adds r2, r1, r0
	ldr r3, _080D8C30 @ =0x02039D2C
	ldrh r1, [r3, #0x00]
	ldrh r0, [r2, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _080D8C0C
	ldrh r1, [r2, #0x02]
	movs r0, #0x34
	adds r5, r1, #0x0
	muls r5, r0
	ldr r0, _080D8C34 @ =0x08F70AB0
	adds r5, r5, r0
	ldr r0, [r5, #0x14]
	movs r1, #0x80
	lsls r1, r1, #0x01
	bl LoadObjTiles
	lsls r4, r6, #0x02
	ldr r2, [sp, #0x020]
	adds r1, r4, r2
	str r0, [r1, #0x00]
	ldr r0, [r5, #0x18]
	movs r1, #0x20
	bl LoadObjPalette
	mov r3, r10
	adds r1, r4, r3
	str r0, [r1, #0x00]
	add r4, r9
	ldr r0, [r5, #0x10]
	str r0, [r4, #0x00]
	adds r0, r6, #0x1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, r8
	bcs _080D8C16
_080D8C0C:
	adds r0, r7, #0x1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #0x07
	bls _080D8BBE
_080D8C16:
	adds r0, r6, #0x0
	add sp, #0x024
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_080D8C28: .4byte 0x096FDE24
_080D8C2C: .4byte 0x02039BB0
_080D8C30: .4byte 0x02039D2C
_080D8C34: .4byte 0x08F70AB0
.syntax divided

.syntax unified
	.align 2, 0
	.global func_080D1078
	.thumb
	.thumb_func
	.type func_080D1078, %function
func_080D1078: @ 080D1078
	push {r4, r5, lr}
	add sp, #-0x0D8
	adds r5, r0, #0x0
	ldr r1, _080D10D4 @ =0x096FD778
	mov r0, sp
	movs r2, #0xD8
	bl _0811F030
	bl func_080D1710
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x0D
	bls _080D10A6
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x03
	ands r0, r1
	adds r0, r4, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_080D10A6:
	lsls r1, r4, #0x01
	adds r1, r1, r4
	lsls r1, r1, #0x02
	mov r2, sp
	adds r0, r2, r1
	ldr r0, [r0, #0x00]
	ldr r2, _080D10D8 @ =0x000AB300
	adds r0, r0, r2
	str r0, [r5, #0x00]
	add r0, sp, #0x004
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	ldr r2, _080D10DC @ =0x00057100
	adds r0, r0, r2
	str r0, [r5, #0x04]
	add r0, sp, #0x008
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r5, #0x08]
	add sp, #0x0D8
	pop {r4, r5}
	pop {r0}
	bx r0
_080D10D4: .4byte 0x096FD778
_080D10D8: .4byte 0x000AB300
_080D10DC: .4byte 0x00057100
.syntax divided

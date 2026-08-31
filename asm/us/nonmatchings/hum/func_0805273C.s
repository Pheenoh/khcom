.syntax unified
	.align 2, 0
	.global func_0805273C
	.thumb
	.thumb_func
	.type func_0805273C, %function
func_0805273C: @ 0805273C
	push {r4, r5, lr}
	add sp, #-0x00C
	adds r5, r0, #0x0
	adds r4, r1, #0x0
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x06
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bne _080527A2
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x1D
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x08
	ldr r1, _080527AC @ =0xFFFFF200
	adds r0, r0, r1
	ldr r1, [r4, #0x28]
	adds r1, r1, r0
	str r1, [sp, #0x000]
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0F
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x08
	ldr r1, _080527B0 @ =0xFFFFF900
	adds r0, r0, r1
	ldr r1, [r4, #0x2C]
	adds r1, r1, r0
	str r1, [sp, #0x004]
	ldr r0, [r4, #0x30]
	str r0, [sp, #0x008]
	movs r1, #0x88
	lsls r1, r1, #0x02
	adds r0, r5, r1
	ldr r1, _080527B4 @ =0x09EDB698
	mov r2, sp
	bl TaskCreate
_080527A2:
	add sp, #0x00C
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080527AC: .4byte 0xFFFFF200
_080527B0: .4byte 0xFFFFF900
_080527B4: .4byte 0x09EDB698
.syntax divided

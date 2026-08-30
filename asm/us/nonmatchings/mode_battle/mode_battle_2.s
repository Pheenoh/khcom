.syntax unified
	.align 2, 0
	.global mode_battle_2
	.thumb
	.thumb_func
	.type mode_battle_2, %function
mode_battle_2: @ 0800A5A4
	push {r4, lr}
	ldr r2, _0800A5FC @ =0x02039BB0
	ldr r0, [r2, #0x08]
	movs r1, #0x05
	negs r1, r1
	ands r0, r1
	str r0, [r2, #0x08]
	bl func_08012810
	ldr r4, _0800A600 @ =0x02039B84
	ldr r0, [r4, #0x00]
	adds r0, #0x54
	bl func_08000F0C
	ldr r0, [r4, #0x00]
	adds r0, #0x40
	bl func_08000F0C
	ldr r0, [r4, #0x00]
	adds r0, #0x2C
	bl func_08000F0C
	bl func_0801C104
	ldr r0, [r4, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0800A5F0
	ldr r0, _0800A604 @ =0x02039B9C
	ldr r0, [r0, #0x00]
	bl func_080009C4
_0800A5F0:
	ldr r0, [r4, #0x00]
	bl func_080009C4
	pop {r4}
	pop {r0}
	bx r0
_0800A5FC: .4byte 0x02039BB0
_0800A600: .4byte 0x02039B84
_0800A604: .4byte 0x02039B9C
.syntax divided

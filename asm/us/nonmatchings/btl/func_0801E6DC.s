.syntax unified
	.align 2, 0
	.global func_0801E6DC
	.thumb
	.thumb_func
	.type func_0801E6DC, %function
func_0801E6DC: @ 0801E6DC
	push {r4, lr}
	add sp, #-0x028
	adds r4, r0, #0x0
	movs r1, #0x92
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x78]
	cmp r0, #0x00
	bne _0801E78A
	ldr r0, _0801E71C @ =0x02039B84
	ldr r3, [r0, #0x00]
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x07
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0801E730
	movs r1, #0xB9
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0801E724
	ldr r0, _0801E720 @ =0x02039B9C
	ldr r0, [r0, #0x00]
	ldr r2, [r0, #0x7C]
	b _0801E726
	.byte 0x00, 0x00
_0801E71C: .4byte 0x02039B84
_0801E720: .4byte 0x02039B9C
_0801E724:
	ldr r2, [r3, #0x7C]
_0801E726:
	movs r1, #0x2C
	ldsh r0, [r2, r1]
	cmp r0, #0x00
	ble _0801E788
	b _0801E784
_0801E730:
	movs r4, #0x00
	adds r0, r3, #0x0
	adds r0, #0x80
	bl func_08000C8C
	adds r2, r0, #0x0
	cmp r2, #0x00
	beq _0801E768
	str r2, [sp, #0x000]
	movs r4, #0x01
_0801E744:
	adds r0, r2, #0x0
	adds r0, #0xB8
	bl func_08000CD4
	adds r2, r0, #0x0
	cmp r2, #0x00
	beq _0801E768
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #0x02
	add r1, sp
	str r2, [r1, #0x00]
	adds r0, #0x01
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x09
	ble _0801E744
_0801E768:
	lsls r0, r4, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0x00
	beq _0801E788
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r4, #0x0
	bl __modsi3
	lsls r0, r0, #0x02
	add r0, sp
	ldr r2, [r0, #0x00]
_0801E784:
	adds r0, r2, #0x0
	b _0801E78A
_0801E788:
	movs r0, #0x00
_0801E78A:
	add sp, #0x028
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided

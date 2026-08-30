.syntax unified
	.align 2, 0
	.global func_0805A574
	.thumb
	.thumb_func
	.type func_0805A574, %function
func_0805A574: @ 0805A574
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	ldr r0, _0805A594 @ =0x08155554
	adds r6, r1, r0
	ldr r0, [r6, #0x10]
	cmp r0, #0x00
	beq _0805A5D6
	movs r7, #0x01
	movs r0, #0x01
	mov r8, r0
	movs r5, #0x00
	b _0805A5C4
_0805A594: .4byte 0x08155554
_0805A598:
	ldr r0, [r6, #0x10]
	lsls r4, r5, #0x01
	adds r0, r4, r0
	ldrh r0, [r0, #0x00]
	bl func_0800FF70
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _0805A628
	ldr r0, [r6, #0x10]
	adds r0, r4, r0
	ldrh r0, [r0, #0x00]
	bl func_0800FF00
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _0805A5BE
	movs r7, #0x00
	b _0805A5C2
_0805A5BE:
	movs r0, #0x00
	mov r8, r0
_0805A5C2:
	adds r5, #0x01
_0805A5C4:
	ldrh r0, [r6, #0x08]
	cmp r5, r0
	blt _0805A598
	cmp r7, #0x00
	bne _0805A61C
	mov r0, r8
	cmp r0, #0x00
	bne _0805A62C
	b _0805A624
_0805A5D6:
	ldr r0, [r6, #0x0C]
	cmp r0, #0x00
	beq _0805A62C
	movs r4, #0x01
	movs r7, #0x01
	movs r5, #0x00
	b _0805A612
_0805A5E4:
	ldr r0, [r6, #0x0C]
	lsls r1, r5, #0x01
	adds r1, r1, r0
	ldrh r0, [r1, #0x00]
	bl func_0805A574
	cmp r0, #0x01
	beq _0805A628
	cmp r0, #0x01
	bgt _0805A5FE
	cmp r0, #0x00
	beq _0805A608
	b _0805A610
_0805A5FE:
	cmp r0, #0x02
	beq _0805A60A
	cmp r0, #0x03
	beq _0805A60E
	b _0805A610
_0805A608:
	movs r4, #0x00
_0805A60A:
	movs r7, #0x00
	b _0805A610
_0805A60E:
	movs r4, #0x00
_0805A610:
	adds r5, #0x01
_0805A612:
	ldrh r0, [r6, #0x08]
	cmp r5, r0
	blt _0805A5E4
	cmp r4, #0x00
	beq _0805A620
_0805A61C:
	movs r0, #0x02
	b _0805A62E
_0805A620:
	cmp r7, #0x00
	bne _0805A62C
_0805A624:
	movs r0, #0x00
	b _0805A62E
_0805A628:
	movs r0, #0x01
	b _0805A62E
_0805A62C:
	movs r0, #0x03
_0805A62E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided

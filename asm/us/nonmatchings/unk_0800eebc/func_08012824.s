.syntax unified
	.align 2, 0
	.global func_08012824
	.thumb
	.thumb_func
	.type func_08012824, %function
func_08012824: @ 08012824
	push {r4, r5, r6, lr}
	ldr r6, _080128AC @ =0x02039B84
	ldr r5, [r6, #0x00]
	ldr r3, [r5, #0x68]
	ldr r4, [r5, #0x6C]
	movs r0, #0x80
	lsls r0, r0, #0x0F
	adds r1, r3, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	beq _0801286C
	ldr r2, _080128B0 @ =0xFFBFFFFF
	adds r0, r3, #0x0
	ands r0, r2
	adds r1, r4, #0x0
	str r0, [r5, #0x68]
	str r1, [r5, #0x6C]
	ldr r4, _080128B4 @ =0x02034928
	ldr r1, [r4, #0x00]
	ldrh r2, [r1, #0x34]
	ldr r0, _080128B8 @ =0x0000FFFD
	ands r0, r2
	strh r0, [r1, #0x34]
	movs r0, #0x00
	str r0, [r1, #0x04]
	bl func_08006B4C
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x00]
	movs r1, #0x10
	movs r2, #0x10
	bl func_080057A0
_0801286C:
	ldr r4, _080128B4 @ =0x02034928
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x04]
	cmp r0, #0x00
	beq _080128E0
	bl _call_via_r0
	ldr r3, [r6, #0x00]
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _080128E0
	adds r1, r3, #0x0
	adds r1, #0xD0
	ldr r2, [r4, #0x00]
	ldr r0, [r2, #0x14]
	str r0, [r1, #0x00]
	ldrh r1, [r2, #0x34]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0x00
	beq _080128BC
	ldr r0, [r2, #0x00]
	movs r1, #0x00
	bl SetBgPriority
	b _080128E0
	.byte 0x00, 0x00
_080128AC: .4byte 0x02039B84
_080128B0: .4byte 0xFFBFFFFF
_080128B4: .4byte 0x02034928
_080128B8: .4byte 0x0000FFFD
_080128BC:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0x00
	beq _080128D8
	ldr r0, [r2, #0x00]
	movs r1, #0x01
	bl SetBgPriority
	ldr r0, [r6, #0x00]
	adds r0, #0xD8
	movs r1, #0xFF
	lsls r1, r1, #0x08
	strh r1, [r0, #0x00]
	b _080128E0
_080128D8:
	adds r1, r3, #0x0
	adds r1, #0xD8
	movs r0, #0x08
	strh r0, [r1, #0x00]
_080128E0:
	bl func_08006954
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided

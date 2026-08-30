.syntax unified
	.align 2, 0
	.global func_080E5D6C
	.thumb
	.thumb_func
	.type func_080E5D6C, %function
func_080E5D6C: @ 080E5D6C
	push {r4, r5, r6, lr}
	add sp, #-0x004
	adds r5, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	ldr r0, [r5, #0x00]
	ldr r4, [r0, #0x00]
	ldrb r0, [r5, #0x1C]
	lsrs r0, r0, #0x06
	cmp r0, #0x01
	beq _080E5DA2
	cmp r0, #0x01
	bgt _080E5D90
	cmp r0, #0x00
	beq _080E5D96
	b _080E5DB6
_080E5D90:
	cmp r0, #0x02
	beq _080E5DB0
	b _080E5DB6
_080E5D96:
	lsls r0, r1, #0x05
	adds r4, r4, r0
	ldrh r1, [r5, #0x04]
	movs r0, #0x01
	orrs r0, r1
	b _080E5DC0
_080E5DA2:
	lsls r0, r1, #0x05
	adds r0, #0x10
	adds r4, r4, r0
	ldrh r1, [r5, #0x04]
	movs r0, #0x01
	orrs r0, r1
	b _080E5DC0
_080E5DB0:
	lsls r0, r1, #0x05
	adds r0, #0x10
	b _080E5DB8
_080E5DB6:
	lsls r0, r1, #0x05
_080E5DB8:
	adds r4, r4, r0
	ldrh r1, [r5, #0x04]
	ldr r0, _080E5DE8 @ =0x0000FFFE
	ands r0, r1
_080E5DC0:
	strh r0, [r5, #0x04]
	adds r0, r5, #0x0
	adds r0, #0xA4
	ldrb r1, [r4, #0x0C]
	ldr r3, [r4, #0x04]
	ldr r2, [r4, #0x00]
	str r2, [sp, #0x000]
	adds r2, r6, #0x0
	bl func_08005974
	adds r0, r5, #0x0
	adds r0, #0xBC
	ldr r0, [r0, #0x00]
	ldr r1, [r4, #0x08]
	bl func_08002A10
	add sp, #0x004
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080E5DE8: .4byte 0x0000FFFE
.syntax divided

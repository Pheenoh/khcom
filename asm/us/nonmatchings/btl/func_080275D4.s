.syntax unified
	.align 2, 0
	.global func_080275D4
	.thumb
	.thumb_func
	.type func_080275D4, %function
func_080275D4: @ 080275D4
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x014
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	adds r0, r6, #0x0
	adds r0, #0x10
	bl AnimGetGfx
	mov r10, r0
	adds r4, r5, #0x0
	adds r4, #0x44
	bl func_080128EC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _0802761C
	ldr r1, _08027614 @ =0x03007554
	movs r2, #0xF1
	lsls r2, r2, #0x04
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	movs r0, #0x06
	movs r1, #0x0C
	bl SetBlendAlpha
	ldr r3, _08027618 @ =0x00000804
	mov r8, r3
	b _08027628
_08027614: .4byte 0x03007554
_08027618: .4byte 0x00000804
_0802761C:
	ldr r0, [r4, #0x08]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
_08027628:
	ldrh r1, [r6, #0x0C]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _08027638
	ldr r2, [r6, #0x2C]
	adds r1, r2, #0x0
	b _08027658
_08027638:
	ldr r2, [r6, #0x2C]
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r2, r0
	bne _0802764E
	adds r1, r2, #0x0
	movs r0, #0x01
	mov r3, r8
	orrs r3, r0
	mov r8, r3
	b _08027658
_0802764E:
	ldr r0, _08027668 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x24]
	negs r1, r0
	adds r2, r0, #0x0
_08027658:
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r2, r0
	bne _0802766C
	cmp r1, r2
	bne _0802766C
	movs r7, #0x00
	b _08027680
_08027668: .4byte 0x02039B84
_0802766C:
	cmp r2, #0xFF
	bgt _08027676
	movs r0, #0x00
	movs r3, #0x00
	b _0802767A
_08027676:
	movs r0, #0x00
	movs r3, #0x01
_0802767A:
	bl AllocObjAffine
	adds r7, r0, #0x0
_08027680:
	ldr r0, _080276D0 @ =0x0000FFF0
	mov r9, r0
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r6, #0x00]
	ldr r3, [r6, #0x04]
	ldr r0, [r6, #0x08]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl WorldToScreen
	ldr r0, [r5, #0x04]
	ldr r1, [r6, #0x28]
	bl func_08002A10
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r4, r2]
	ldr r3, [r5, #0x04]
	ldr r2, [r5, #0x08]
	str r2, [sp, #0x000]
	str r7, [sp, #0x004]
	mov r2, r8
	str r2, [sp, #0x008]
	mov r2, r9
	str r2, [sp, #0x00C]
	mov r2, r10
	bl DrawSprite
	add sp, #0x014
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080276D0: .4byte 0x0000FFF0
.syntax divided

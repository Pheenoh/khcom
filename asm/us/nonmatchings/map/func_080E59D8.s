.syntax unified
	.align 2, 0
	.global func_080E59D8
	.thumb
	.thumb_func
	.type func_080E59D8, %function
func_080E59D8: @ 080E59D8
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x008
	mov r8, r0
	mov r5, r8
	adds r5, #0x08
	movs r0, #0x01
	bl func_080E54A0
	adds r3, r0, #0x0
	ldrh r0, [r3, #0x02]
	ldrh r1, [r3, #0x00]
	subs r0, r0, r1
	subs r0, #0x02
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r10, r0
	ldr r0, _080E5A18 @ =0x0203C7AC
	ldr r1, [r0, #0x00]
	ldrh r0, [r1, #0x0A]
	ldrh r1, [r1, #0x08]
	subs r0, r0, r1
	subs r0, #0x02
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x000]
	movs r0, #0x00
	mov r9, r0
	b _080E5AB0
_080E5A18: .4byte 0x0203C7AC
_080E5A1C:
	ldr r0, _080E5A6C @ =0x0203C7AC
	ldr r0, [r0, #0x00]
	ldrh r0, [r0, #0x08]
	add r0, r9
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r6, #0x00
	cmp r6, r10
	bge _080E5AAC
	lsls r7, r0, #0x10
_080E5A30:
	ldrh r0, [r3, #0x00]
	adds r0, r0, r6
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	adds r0, r4, #0x0
	asrs r1, r7, #0x10
	str r3, [sp, #0x004]
	bl func_080E548C
	adds r2, r0, #0x0
	ldr r1, [r2, #0x0C]
	ldr r3, [sp, #0x004]
	ldr r0, [r3, #0x04]
	cmp r1, r0
	bne _080E5AA6
	ldrh r1, [r2, #0x00]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0x00
	beq _080E5AA6
	ldrb r0, [r2, #0x02]
	cmp r0, #0x04
	bne _080E5A70
	movs r0, #0x53
	mov r1, r8
	strb r0, [r1, #0x18]
	lsls r0, r4, #0x0D
	movs r1, #0xC0
	lsls r1, r1, #0x05
	b _080E5A80
_080E5A6C: .4byte 0x0203C7AC
_080E5A70:
	cmp r0, #0x06
	bne _080E5AA6
	movs r0, #0xAD
	mov r1, r8
	strb r0, [r1, #0x18]
	lsls r0, r4, #0x0D
	movs r1, #0x80
	lsls r1, r1, #0x04
_080E5A80:
	adds r0, r0, r1
	str r0, [r5, #0x00]
	asrs r0, r7, #0x04
	movs r1, #0xC0
	lsls r1, r1, #0x05
	adds r0, r0, r1
	str r0, [r5, #0x04]
	movs r0, #0x00
	str r0, [r5, #0x08]
	adds r0, r5, #0x0
	bl func_080DFF30
	str r0, [r5, #0x0C]
	str r0, [r5, #0x08]
	ldr r1, [r5, #0x04]
	subs r1, r1, r0
	str r1, [r5, #0x04]
	movs r0, #0x01
	b _080E5AB8
_080E5AA6:
	adds r6, #0x01
	cmp r6, r10
	blt _080E5A30
_080E5AAC:
	movs r0, #0x01
	add r9, r0
_080E5AB0:
	ldr r1, [sp, #0x000]
	cmp r9, r1
	blt _080E5A1C
	movs r0, #0x00
_080E5AB8:
	add sp, #0x008
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided

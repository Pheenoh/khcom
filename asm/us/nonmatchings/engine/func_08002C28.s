.syntax unified
	.align 2, 0
	.global func_08002C28
	.thumb
	.thumb_func
	.type func_08002C28, %function
func_08002C28: @ 08002C28
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	ldr r0, _08002C98 @ =0x030074C8
	mov r8, r0
	ldr r6, [r0, #0x00]
	ldr r1, _08002C9C @ =0x00002BAC
	mov r12, r1
	adds r4, r6, r1
	ldrh r0, [r4, #0x00]
	cmp r0, #0x1F
	bhi _08002CA8
	cmp r5, #0x00
	beq _08002CA8
	ldr r1, _08002CA0 @ =0x08121400
	lsls r0, r5, #0x01
	adds r0, r0, r1
	movs r3, #0x00
	ldsh r2, [r0, r3]
	adds r0, r5, #0x0
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r1
	movs r1, #0x00
	ldsh r3, [r0, r1]
	ldrh r1, [r4, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	ldr r1, _08002CA4 @ =0x000028AC
	adds r0, r0, r1
	adds r0, r6, r0
	strh r3, [r0, #0x00]
	strh r2, [r0, #0x02]
	negs r2, r2
	strh r2, [r0, #0x04]
	strh r3, [r0, #0x06]
	ldrh r1, [r4, #0x00]
	strh r1, [r0, #0x08]
	strb r7, [r0, #0x0A]
	movs r1, #0x80
	lsls r1, r1, #0x01
	str r1, [r0, #0x0C]
	str r1, [r0, #0x10]
	strb r5, [r0, #0x14]
	mov r3, r8
	ldr r2, [r3, #0x00]
	add r2, r12
	ldrh r1, [r2, #0x00]
	adds r1, #0x01
	strh r1, [r2, #0x00]
	b _08002CAA
_08002C98: .4byte 0x030074C8
_08002C9C: .4byte 0x00002BAC
_08002CA0: .4byte 0x08121400
_08002CA4: .4byte 0x000028AC
_08002CA8:
	movs r0, #0x00
_08002CAA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided

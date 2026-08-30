.syntax unified
	.align 2, 0
	.global func_080787B8
	.thumb
	.thumb_func
	.type func_080787B8, %function
func_080787B8: @ 080787B8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r12, r0
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
	lsls r1, r2, #0x01
	adds r0, #0xA8
	adds r0, r0, r1
	ldrh r5, [r0, #0x00]
	movs r4, #0x00
	movs r3, #0x00
	ldr r0, _0807884C @ =0x02034A98
	mov r8, r0
	cmp r4, r5
	bcs _08078818
	lsls r1, r2, #0x02
	mov r0, r12
	adds r0, #0x44
	adds r0, r0, r1
	ldr r6, [r0, #0x00]
	ldr r7, _08078850 @ =0x0000FFFF
_080787E4:
	lsls r0, r3, #0x01
	adds r0, r0, r3
	lsls r0, r0, #0x02
	adds r2, r0, r6
	ldrh r1, [r2, #0x06]
	adds r0, r7, #0x0
	ands r0, r1
	cmp r0, #0x00
	bne _0807880E
	ldr r0, [r2, #0x08]
	ldr r1, _08078854 @ =0x00FF00FF
	ands r0, r1
	cmp r0, #0x00
	bne _0807880E
	ldr r1, [r2, #0x00]
	ldr r0, _08078858 @ =0x0000FFFE
	cmp r1, r0
	beq _0807880E
	adds r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_0807880E:
	adds r0, r3, #0x1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, r5
	bcc _080787E4
_08078818:
	mov r1, r8
	ldr r0, [r1, #0x00]
	ldr r0, [r0, #0x78]
	movs r1, #0x80
	lsls r1, r1, #0x0D
	ands r0, r1
	cmp r0, #0x00
	beq _08078840
	mov r0, r12
	adds r0, #0xB8
	movs r1, #0x00
	ldsb r1, [r0, r1]
	lsls r1, r1, #0x01
	subs r0, #0x08
	adds r0, r0, r1
	movs r1, #0x00
	ldsh r0, [r0, r1]
	cmp r0, #0x01
	bne _08078840
	movs r4, #0x00
_08078840:
	adds r0, r4, #0x0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_0807884C: .4byte 0x02034A98
_08078850: .4byte 0x0000FFFF
_08078854: .4byte 0x00FF00FF
_08078858: .4byte 0x0000FFFE
.syntax divided

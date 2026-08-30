.syntax unified
	.align 2, 0
	.global func_08078754
	.thumb
	.thumb_func
	.type func_08078754, %function
func_08078754: @ 08078754
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
	lsls r1, r2, #0x01
	adds r0, #0xA8
	adds r0, r0, r1
	ldrh r4, [r0, #0x00]
	movs r5, #0x00
	movs r3, #0x00
	cmp r5, r4
	bcs _080787A6
	lsls r1, r2, #0x02
	adds r0, r6, #0x0
	adds r0, #0x44
	adds r0, r0, r1
	ldr r6, [r0, #0x00]
	ldr r0, _080787B0 @ =0x0000FFFF
	mov r12, r0
	ldr r7, _080787B4 @ =0x00FF00FF
_0807877C:
	lsls r0, r3, #0x01
	adds r0, r0, r3
	lsls r0, r0, #0x02
	adds r2, r0, r6
	ldrh r1, [r2, #0x06]
	mov r0, r12
	ands r0, r1
	cmp r0, #0x00
	bne _0807879C
	ldr r0, [r2, #0x08]
	ands r0, r7
	cmp r0, #0x00
	bne _0807879C
	adds r0, r5, #0x1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
_0807879C:
	adds r0, r3, #0x1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, r4
	bcc _0807877C
_080787A6:
	adds r0, r5, #0x0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080787B0: .4byte 0x0000FFFF
_080787B4: .4byte 0x00FF00FF
.syntax divided

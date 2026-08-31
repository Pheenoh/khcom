.syntax unified
	.align 2, 0
	.global func_080038E4
	.thumb
	.thumb_func
	.type func_080038E4, %function
func_080038E4: @ 080038E4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0x0
	adds r5, r1, #0x0
	cmp r5, #0x00
	beq _08003964
	cmp r2, #0x00
	beq _08003964
	ldr r0, [r6, #0x28]
	cmp r0, #0x02
	bne _08003964
	ldr r0, [r6, #0x20]
	cmp r0, r5
	bne _08003908
	ldr r0, [r6, #0x00]
	cmp r0, r2
	beq _08003964
_08003908:
	str r2, [r6, #0x00]
	str r5, [r6, #0x20]
	ldrh r0, [r5, #0x00]
	adds r5, #0x02
	movs r1, #0x00
	mov r8, r1
	cmp r0, #0x00
	beq _08003958
	adds r7, r0, #0x0
_0800391A:
	ldrh r0, [r5, #0x00]
	ldrh r1, [r5, #0x02]
	bl func_08001DB0
	adds r4, r0, #0x0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldrh r0, [r5, #0x04]
	ldr r2, _0800395C @ =0x000003FF
	adds r1, r2, #0x0
	ands r1, r0
	lsls r1, r1, #0x05
	ldr r0, [r6, #0x00]
	adds r0, r0, r1
	ldrh r1, [r6, #0x06]
	add r1, r8
	lsls r1, r1, #0x05
	ldr r2, _08003960 @ =0x06010000
	adds r1, r1, r2
	lsls r2, r4, #0x15
	lsrs r2, r2, #0x10
	bl RequestDma3Copy
	add r4, r8
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r8, r4
	adds r5, #0x06
	subs r7, #0x01
	cmp r7, #0x00
	bne _0800391A
_08003958:
	movs r0, #0x01
	b _08003966
_0800395C: .4byte 0x000003FF
_08003960: .4byte 0x06010000
_08003964:
	movs r0, #0x00
_08003966:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided

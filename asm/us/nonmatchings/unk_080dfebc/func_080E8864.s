.syntax unified
	.align 2, 0
	.global func_080E8864
	.thumb
	.thumb_func
	.type func_080E8864, %function
func_080E8864: @ 080E8864
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x004
	adds r7, r0, #0x0
	ldr r0, _080E8918 @ =0x0203C7AC
	ldr r1, [r0, #0x00]
	ldrb r2, [r7, #0x04]
	ldrh r0, [r1, #0x04]
	subs r0, r0, r2
	adds r0, #0x01
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	ldrh r0, [r1, #0x0A]
	ldrh r1, [r1, #0x08]
	subs r0, r0, r1
	adds r0, #0x07
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r10, r0
	subs r1, #0x07
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x000]
	movs r1, #0x00
	cmp r1, r10
	bge _080E8906
_080E88A0:
	ldr r2, [sp, #0x000]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r4, #0x00
	adds r1, #0x01
	mov r9, r1
	cmp r4, r8
	bge _080E8900
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
_080E88BA:
	lsls r4, r4, #0x10
	asrs r5, r4, #0x10
	ldr r2, [r7, #0x00]
	adds r0, r5, #0x0
	adds r1, r6, #0x0
	bl func_080E87EC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080E88F2
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x64
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r7, #0x06]
	cmp r0, r1
	bcs _080E88F2
	ldr r2, [r7, #0x08]
	ldr r3, [r7, #0x0C]
	adds r0, r5, #0x0
	adds r1, r6, #0x0
	bl func_080E8724
_080E88F2:
	movs r2, #0x80
	lsls r2, r2, #0x09
	adds r0, r4, r2
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r8
	blt _080E88BA
_080E8900:
	mov r1, r9
	cmp r1, r10
	blt _080E88A0
_080E8906:
	add sp, #0x004
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080E8918: .4byte 0x0203C7AC
.syntax divided

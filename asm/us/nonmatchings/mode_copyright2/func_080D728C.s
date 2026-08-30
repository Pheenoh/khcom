.syntax unified
	.align 2, 0
	.global func_080D728C
	.thumb
	.thumb_func
	.type func_080D728C, %function
func_080D728C: @ 080D728C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x00C
	mov r9, r0
	mov r10, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r8, r2
	cmp r2, #0x06
	bls _080D72AA
	movs r0, #0x06
	mov r8, r0
_080D72AA:
	movs r4, #0x01
	mov r0, r8
	cmp r0, #0x00
	beq _080D72C0
	mov r6, r8
_080D72B4:
	lsls r0, r4, #0x02
	adds r0, r0, r4
	lsls r4, r0, #0x01
	subs r6, #0x01
	cmp r6, #0x00
	bne _080D72B4
_080D72C0:
	subs r0, r4, #0x1
	cmp r10, r0
	bgt _080D72CE
	mov r0, r10
	cmp r0, #0x00
	bge _080D72D0
	movs r0, #0x00
_080D72CE:
	mov r10, r0
_080D72D0:
	mov r0, r8
	cmp r0, #0x00
	beq _080D7300
	mov r7, sp
	mov r6, r8
_080D72DA:
	mov r0, r10
	adds r1, r4, #0x0
	bl __modsi3
	adds r5, r0, #0x0
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl __divsi3
	adds r4, r0, #0x0
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl __divsi3
	strh r0, [r7, #0x00]
	adds r7, #0x02
	subs r6, #0x01
	cmp r6, #0x00
	bne _080D72DA
_080D7300:
	mov r0, r8
	cmp r0, #0x00
	beq _080D7326
	mov r4, sp
	ldr r5, _080D7338 @ =0x09801C98
	mov r6, r8
_080D730C:
	ldrh r0, [r4, #0x00]
	lsls r0, r0, #0x05
	adds r0, r0, r5
	mov r1, r9
	movs r2, #0x20
	bl func_080043B4
	movs r0, #0x20
	add r9, r0
	adds r4, #0x02
	subs r6, #0x01
	cmp r6, #0x00
	bne _080D730C
_080D7326:
	mov r0, r9
	add sp, #0x00C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_080D7338: .4byte 0x09801C98
.syntax divided

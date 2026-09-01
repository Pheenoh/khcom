.syntax unified
	.align 2, 0
	.global func_080B3204
	.thumb
	.thumb_func
	.type func_080B3204, %function
func_080B3204: @ 080B3204
	push {r4, r5, r6, r7, lr}
	add sp, #-0x008
	movs r4, #0x00
	movs r7, #0x80
	lsls r7, r7, #0x04
	ldr r6, _080B3334 @ =0x0203AB20
	movs r5, #0x04
_080B3212:
	ldrh r0, [r6, #0x00]
	lsls r1, r0, #0x10
	asrs r0, r1, #0x10
	cmp r0, r7
	beq _080B3228
	lsrs r0, r1, #0x10
	bl func_08060A2C
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_080B3228:
	adds r6, #0x02
	subs r5, #0x01
	cmp r5, #0x00
	bge _080B3212
	lsls r0, r4, #0x10
	asrs r5, r0, #0x10
	mov r4, sp
	adds r0, r5, #0x0
	movs r1, #0x64
	bl __divsi3
	strh r0, [r4, #0x00]
	adds r0, r5, #0x0
	movs r1, #0x64
	bl __modsi3
	adds r5, r0, #0x0
	mov r4, sp
	movs r1, #0x0A
	bl __divsi3
	strh r0, [r4, #0x02]
	adds r0, r5, #0x0
	movs r1, #0x0A
	bl __modsi3
	adds r5, r0, #0x0
	mov r0, sp
	strh r5, [r0, #0x04]
	movs r1, #0x00
	ldsh r0, [r0, r1]
	lsls r0, r0, #0x05
	ldr r4, _080B3338 @ =0x096B5DA4
	adds r0, r0, r4
	ldr r1, _080B333C @ =0x060001A0
	movs r2, #0x20
	bl RequestDma3Copy
	mov r0, sp
	movs r1, #0x02
	ldsh r0, [r0, r1]
	lsls r0, r0, #0x05
	adds r0, r0, r4
	ldr r1, _080B3340 @ =0x060001C0
	movs r2, #0x20
	bl RequestDma3Copy
	mov r0, sp
	movs r1, #0x04
	ldsh r0, [r0, r1]
	lsls r0, r0, #0x05
	adds r0, r0, r4
	ldr r1, _080B3344 @ =0x060001E0
	movs r2, #0x20
	bl RequestDma3Copy
	movs r4, #0x00
	ldr r0, _080B3334 @ =0x0203AB20
	movs r7, #0x80
	lsls r7, r7, #0x04
	adds r6, r0, #0x0
	adds r6, #0x0A
	movs r5, #0x04
_080B32A6:
	ldrh r0, [r6, #0x00]
	lsls r1, r0, #0x10
	asrs r0, r1, #0x10
	cmp r0, r7
	beq _080B32BC
	lsrs r0, r1, #0x10
	bl func_08060A2C
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_080B32BC:
	adds r6, #0x02
	subs r5, #0x01
	cmp r5, #0x00
	bge _080B32A6
	lsls r0, r4, #0x10
	asrs r5, r0, #0x10
	mov r4, sp
	adds r0, r5, #0x0
	movs r1, #0x64
	bl __divsi3
	strh r0, [r4, #0x00]
	adds r0, r5, #0x0
	movs r1, #0x64
	bl __modsi3
	adds r5, r0, #0x0
	mov r4, sp
	movs r1, #0x0A
	bl __divsi3
	strh r0, [r4, #0x02]
	adds r0, r5, #0x0
	movs r1, #0x0A
	bl __modsi3
	adds r5, r0, #0x0
	mov r0, sp
	strh r5, [r0, #0x04]
	movs r1, #0x00
	ldsh r0, [r0, r1]
	lsls r0, r0, #0x05
	ldr r4, _080B3338 @ =0x096B5DA4
	adds r0, r0, r4
	ldr r1, _080B3348 @ =0x06000200
	movs r2, #0x20
	bl RequestDma3Copy
	mov r0, sp
	movs r1, #0x02
	ldsh r0, [r0, r1]
	lsls r0, r0, #0x05
	adds r0, r0, r4
	ldr r1, _080B334C @ =0x06000220
	movs r2, #0x20
	bl RequestDma3Copy
	mov r0, sp
	movs r1, #0x04
	ldsh r0, [r0, r1]
	lsls r0, r0, #0x05
	adds r0, r0, r4
	ldr r1, _080B3350 @ =0x06000240
	movs r2, #0x20
	bl RequestDma3Copy
	add sp, #0x008
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080B3334: .4byte 0x0203AB20
_080B3338: .4byte 0x096B5DA4
_080B333C: .4byte 0x060001A0
_080B3340: .4byte 0x060001C0
_080B3344: .4byte 0x060001E0
_080B3348: .4byte 0x06000200
_080B334C: .4byte 0x06000220
_080B3350: .4byte 0x06000240
.syntax divided

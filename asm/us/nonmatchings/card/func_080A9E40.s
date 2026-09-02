.syntax unified
	.align 2, 0
	.global func_080A9E40
	.thumb
	.thumb_func
	.type func_080A9E40, %function
func_080A9E40: @ 080A9E40
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x008
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	mov r8, r6
	movs r7, #0x00
	adds r0, r6, #0x0
	bl func_08085B38
	adds r4, r0, #0x0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r5, sp
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl __udivsi3
	strb r0, [r5, #0x00]
	mov r2, sp
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r0, #0x02
	adds r1, r1, r0
	lsls r1, r1, #0x01
	subs r4, r4, r1
	strb r4, [r2, #0x01]
	add r0, sp, #0x004
	movs r1, #0x09
	strb r1, [r0, #0x00]
	strb r1, [r0, #0x01]
	adds r5, r0, #0x0
	cmp r6, #0x01
	beq _080A9E9C
	cmp r6, #0x01
	bgt _080A9E90
	cmp r6, #0x00
	beq _080A9E98
	b _080A9EA8
_080A9E90:
	mov r0, r8
	cmp r0, #0x02
	beq _080A9EA0
	b _080A9EA8
_080A9E98:
	movs r0, #0x00
	b _080A9EA2
_080A9E9C:
	movs r0, #0x01
	b _080A9EA2
_080A9EA0:
	movs r0, #0x02
_080A9EA2:
	bl GetBgCharBase
	adds r7, r0, #0x0
_080A9EA8:
	mov r0, sp
	ldrb r0, [r0, #0x00]
	adds r0, #0x01
	lsls r0, r0, #0x05
	ldr r4, _080A9F04 @ =0x0940F938
	adds r0, r0, r4
	adds r1, r7, #0x0
	adds r1, #0x20
	movs r2, #0x20
	bl RequestDma3Copy
	mov r0, sp
	ldrb r0, [r0, #0x01]
	adds r0, #0x01
	lsls r0, r0, #0x05
	adds r0, r0, r4
	adds r1, r7, #0x0
	adds r1, #0x40
	movs r2, #0x20
	bl RequestDma3Copy
	ldrb r0, [r5, #0x00]
	adds r0, #0x01
	lsls r0, r0, #0x05
	adds r0, r0, r4
	adds r1, r7, #0x0
	adds r1, #0x60
	movs r2, #0x20
	bl RequestDma3Copy
	ldrb r0, [r5, #0x01]
	adds r0, #0x01
	lsls r0, r0, #0x05
	adds r0, r0, r4
	adds r1, r7, #0x0
	adds r1, #0x80
	movs r2, #0x20
	bl RequestDma3Copy
	add sp, #0x008
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080A9F04: .4byte 0x0940F938
.syntax divided

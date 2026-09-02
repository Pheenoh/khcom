.syntax unified
	.align 2, 0
	.global func_080A6B40
	.thumb
	.thumb_func
	.type func_080A6B40, %function
func_080A6B40: @ 080A6B40
	push {r4, r5, r6, lr}
	add sp, #-0x004
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	mov r6, sp
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl __udivsi3
	strb r0, [r6, #0x00]
	mov r2, sp
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #0x02
	adds r1, r1, r0
	lsls r1, r1, #0x01
	subs r4, r4, r1
	strb r4, [r2, #0x01]
	movs r0, #0x03
	bl GetBgCharBase
	adds r4, r0, #0x0
	mov r0, sp
	ldrb r0, [r0, #0x00]
	adds r0, #0x01
	lsls r0, r0, #0x05
	ldr r6, _080A6BB0 @ =0x0940F7B8
	adds r0, r0, r6
	lsls r5, r5, #0x06
	movs r1, #0xD8
	lsls r1, r1, #0x02
	adds r5, r5, r1
	adds r4, r4, r5
	adds r1, r4, #0x0
	movs r2, #0x20
	bl RequestDma3Copy
	mov r0, sp
	ldrb r0, [r0, #0x01]
	adds r0, #0x01
	lsls r0, r0, #0x05
	adds r0, r0, r6
	adds r4, #0x20
	adds r1, r4, #0x0
	movs r2, #0x20
	bl RequestDma3Copy
	add sp, #0x004
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080A6BB0: .4byte 0x0940F7B8
.syntax divided

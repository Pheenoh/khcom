.syntax unified
	.align 2, 0
	.global func_080788CC
	.thumb
	.thumb_func
	.type func_080788CC, %function
func_080788CC: @ 080788CC
	push {r4, r5, lr}
	adds r5, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	movs r2, #0x00
	lsls r1, r4, #0x01
	adds r0, #0xA8
	adds r3, r0, r1
	movs r1, #0x00
	ldsh r0, [r3, r1]
	cmp r2, r0
	bge _0807890C
	lsls r1, r4, #0x02
	adds r0, r5, #0x0
	adds r0, #0x44
	adds r4, r0, r1
_080788EC:
	ldr r1, [r4, #0x00]
	lsls r0, r2, #0x01
	adds r0, r0, r2
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldrb r1, [r0, #0x07]
	cmp r1, #0x00
	bne _080788FE
	strb r1, [r0, #0x08]
_080788FE:
	adds r0, r2, #0x1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	movs r1, #0x00
	ldsh r0, [r3, r1]
	cmp r2, r0
	blt _080788EC
_0807890C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided

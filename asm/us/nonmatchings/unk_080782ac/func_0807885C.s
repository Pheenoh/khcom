.syntax unified
	.align 2, 0
	.global func_0807885C
	.thumb
	.thumb_func
	.type func_0807885C, %function
func_0807885C: @ 0807885C
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
	lsls r1, r2, #0x01
	adds r0, #0xA8
	adds r0, r0, r1
	ldrh r5, [r0, #0x00]
	movs r6, #0x00
	movs r3, #0x00
	cmp r6, r5
	bcs _080788B8
	lsls r1, r2, #0x02
	adds r0, r4, #0x0
	adds r0, #0x44
	adds r0, r0, r1
	ldr r1, [r0, #0x00]
	ldr r4, _080788C0 @ =0x08F70AB0
_08078880:
	lsls r0, r3, #0x01
	adds r0, r0, r3
	lsls r0, r0, #0x02
	adds r2, r0, r1
	ldrb r0, [r2, #0x0A]
	cmp r0, #0x00
	bne _080788AE
	ldr r2, [r2, #0x00]
	ldr r0, _080788C4 @ =0x0000FFFE
	cmp r2, r0
	beq _080788AE
	ldr r0, _080788C8 @ =0x00000FFF
	ands r2, r0
	movs r0, #0x34
	muls r0, r2
	adds r0, r0, r4
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080788AE
	adds r0, r6, #0x1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
_080788AE:
	adds r0, r3, #0x1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, r5
	bcc _08078880
_080788B8:
	adds r0, r6, #0x0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
_080788C0: .4byte 0x08F70AB0
_080788C4: .4byte 0x0000FFFE
_080788C8: .4byte 0x00000FFF
.syntax divided

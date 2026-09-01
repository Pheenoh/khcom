.syntax unified
	.align 2, 0
	.global task_wlogo_hlw_1
	.thumb
	.thumb_func
	.type task_wlogo_hlw_1, %function
task_wlogo_hlw_1: @ 080B5CB0
	push {lr}
	adds r1, r0, #0x0
	ldrb r2, [r1, #0x00]
	cmp r2, #0x01
	beq _080B5CE0
	cmp r2, #0x01
	bgt _080B5CC4
	cmp r2, #0x00
	beq _080B5CCE
	b _080B5D7C
_080B5CC4:
	cmp r2, #0x02
	beq _080B5D1C
	cmp r2, #0x03
	beq _080B5D36
	b _080B5D7C
_080B5CCE:
	ldrh r0, [r1, #0x02]
	adds r0, #0x01
	strh r0, [r1, #0x02]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1D
	bls _080B5D7C
	strh r2, [r1, #0x02]
	b _080B5D2E
_080B5CE0:
	ldrh r0, [r1, #0x02]
	adds r0, #0x01
	strh r0, [r1, #0x02]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x05
	bls _080B5D7C
	movs r0, #0x00
	strh r0, [r1, #0x02]
	ldrb r0, [r1, #0x04]
	adds r0, #0x01
	strb r0, [r1, #0x04]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x0F
	bls _080B5D0A
	movs r0, #0x10
	strb r0, [r1, #0x04]
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
_080B5D0A:
	ldrb r2, [r1, #0x04]
	movs r1, #0x10
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x00
	bl SetBgBlend
	b _080B5D7C
_080B5D1C:
	ldrh r0, [r1, #0x02]
	adds r0, #0x01
	strh r0, [r1, #0x02]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x71
	bls _080B5D7C
	movs r0, #0x00
	strh r0, [r1, #0x02]
_080B5D2E:
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	b _080B5D7C
_080B5D36:
	ldrh r0, [r1, #0x02]
	adds r0, #0x01
	strh r0, [r1, #0x02]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x04
	bls _080B5D7C
	movs r0, #0x00
	strh r0, [r1, #0x02]
	ldrb r0, [r1, #0x04]
	subs r0, #0x01
	strb r0, [r1, #0x04]
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080B5D6C
	movs r0, #0x00
	strb r0, [r1, #0x04]
	movs r0, #0x00
	movs r1, #0x10
	movs r2, #0x00
	bl SetBgBlend
	movs r0, #0x00
	bl DisableBg
	movs r0, #0x00
	b _080B5D7E
_080B5D6C:
	ldrb r2, [r1, #0x04]
	movs r1, #0x10
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x00
	bl SetBgBlend
_080B5D7C:
	movs r0, #0x01
_080B5D7E:
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided

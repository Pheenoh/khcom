.syntax unified
	.align 2, 0
	.global func_080E8F0C
	.thumb
	.thumb_func
	.type func_080E8F0C, %function
func_080E8F0C: @ 080E8F0C
	push {r4, lr}
	movs r4, #0x00
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080E8F38 @ =0x00002710
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	movs r1, #0x00
	ldr r2, _080E8F3C @ =0x09858238
_080E8F26:
	ldrh r0, [r2, #0x00]
	adds r0, r4, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r3, r4
	bcs _080E8F40
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	b _080E8F4A
_080E8F38: .4byte 0x00002710
_080E8F3C: .4byte 0x09858238
_080E8F40:
	adds r2, #0x02
	adds r1, #0x01
	cmp r1, #0x09
	ble _080E8F26
	movs r0, #0x00
_080E8F4A:
	pop {r4}
	pop {r1}
	bx r1
.syntax divided

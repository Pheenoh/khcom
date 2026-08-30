.syntax unified
	.align 2, 0
	.global func_080CA36C
	.thumb
	.thumb_func
	.type func_080CA36C, %function
func_080CA36C: @ 080CA36C
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsls r1, r1, #0x10
	ldr r5, _080CA39C @ =0x09EF4208
	lsrs r4, r0, #0x18
	lsrs r2, r1, #0x18
	lsrs r0, r0, #0x13
	movs r3, #0x1F
	ands r0, r3
	lsrs r1, r1, #0x13
	ands r1, r3
	lsls r2, r2, #0x04
	adds r2, r2, r4
	lsls r2, r2, #0x02
	adds r2, r2, r5
	lsls r1, r1, #0x05
	adds r1, r1, r0
	ldr r0, [r2, #0x00]
	lsls r1, r1, #0x01
	adds r1, r1, r0
	ldrh r0, [r1, #0x00]
	pop {r4, r5}
	pop {r1}
	bx r1
_080CA39C: .4byte 0x09EF4208
.syntax divided

.syntax unified
	.align 2, 0
	.global func_080DA4DC
	.thumb
	.thumb_func
	.type func_080DA4DC, %function
func_080DA4DC: @ 080DA4DC
	push {lr}
	movs r1, #0xAE
	lsls r1, r1, #0x01
	adds r0, r0, r1
	ldr r2, [r0, #0x00]
	adds r1, r2, r1
	ldr r0, [r1, #0x00]
	cmp r0, #0x03
	bne _080DA502
	adds r0, r2, #0x0
	adds r0, #0x14
	bl func_08005B34
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x02
	bhi _080DA502
	movs r0, #0x01
	b _080DA504
_080DA502:
	movs r0, #0x00
_080DA504:
	pop {r1}
	bx r1
.syntax divided
